#pragma once

#include "mesh-pb-constants.h"
#include "stdint.h"
#include <functional>

/**
 * @brief Communication interface to be implemented by the user of the device-ui
 * library. The interface implementation has to be passed when initializing the
 * DeviceScreen.
 * @tparam T
 */

class IClientBase
{
  public:
    enum ConnectionStatus { eDisconnected = 0, eConnected, eConnecting, eDisconnecting, eError };

    using NotifyCallback = std::function<void(ConnectionStatus status, const char *info)>;

    virtual void init(void) = 0;
    virtual bool connect(void) = 0;
    virtual bool disconnect(void) = 0;
    virtual bool isConnected(void) = 0;
    virtual bool isStandalone(void) = 0;
    virtual bool sleep(int16_t pin) { return false; }

    virtual bool send(meshtastic_ToRadio &&to) = 0;
    virtual meshtastic_FromRadio receive(void) = 0;
    virtual ~IClientBase(){};

    // Voicetastic-specific hooks; default impls report "no voice support" so
    // any IClientBase subclass that doesn't care can ignore these entirely.
    // The chat screen calls them in this order:
    //   voiceRecordStart()  - SYM+0 first press
    //   voiceRecordStop()   - SYM+0 second press (audio held, not sent)
    //   voiceRecordSend()   - ENTER while armed
    //   voiceRecordCancel() - any other dismissal
    enum VoiceState : uint8_t { eVoiceIdle = 0, eVoiceRecording = 1, eVoiceArmed = 2 };

    virtual bool voiceRecordStart(uint32_t to_nodenum = 0xFFFFFFFFu, uint8_t channel = 0,
                                  uint32_t max_duration_ms = 30000) { (void)to_nodenum; (void)channel; (void)max_duration_ms; return false; }
    virtual void voiceRecordStop() {}
    virtual bool voiceRecordSend() { return false; }
    virtual void voiceRecordCancel() {}
    virtual VoiceState voiceRecordState() const { return eVoiceIdle; }
    virtual uint32_t voiceRecordElapsedMs() const { return 0; }

    virtual void task_handler(void){};
    virtual void setNotifyCallback(NotifyCallback notifyConnectionStatus) = 0;

  protected:
    IClientBase() = default;
};
