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

    // Codec2 mode selection (firmware-side persistent setting). The settings
    // UI surfaces a dropdown bound to these hooks. Returned/accepted value is
    // the on-wire codec_param ordinal: 0=3.2 kbps, 1=2.4, 2=1.6, 3=1.4, 4=1.3,
    // 5=1.2 (default). Out-of-range values are ignored by the implementation.
    virtual uint8_t voiceGetCodec2Mode() const { return 5; }
    virtual void    voiceSetCodec2Mode(uint8_t /*mode*/) {}

    // Mini-player playback hooks. Received voice messages queue up in the
    // firmware; the chat-screen widget enumerates and plays them on user
    // request. All return harmless defaults if no voice backend is present.
    virtual size_t   voicePlayPendingCount() const { return 0; }
    virtual bool     voicePlayNext() { return false; }
    virtual bool     voicePlayByMessageId(uint32_t /*message_id*/) { return false; }
    virtual void     voicePlayStop() {}
    virtual bool     voicePlayIsPlaying() const { return false; }
    virtual uint32_t voicePlayElapsedMs() const { return 0; }
    virtual uint32_t voicePlayTotalMs() const { return 0; }
    virtual uint32_t voicePlayFromNode() const { return 0; }
    virtual uint32_t voicePlayMessageId() const { return 0; }
    // Inspect a queued message without consuming it. Returns false past end.
    virtual bool     voicePlayPeek(size_t /*index*/, uint32_t &from, uint32_t &message_id,
                                   uint32_t &approx_duration_ms) const
    { from = 0; message_id = 0; approx_duration_ms = 0; return false; }
    // Extended peek: also exposes `to`, channel, and whether the message has
    // already been played at least once. Used by the chat-screen widget to
    // route each bubble into the right chat container and dim played entries.
    virtual bool     voicePlayPeekFull(size_t /*index*/, uint32_t &from, uint32_t &to,
                                       uint8_t &channel, uint32_t &message_id,
                                       uint32_t &approx_duration_ms, bool &played) const
    { from = 0; to = 0; channel = 0; message_id = 0; approx_duration_ms = 0; played = false; return false; }

    virtual void task_handler(void){};
    virtual void setNotifyCallback(NotifyCallback notifyConnectionStatus) = 0;

  protected:
    IClientBase() = default;
};
