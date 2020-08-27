#include "pch.h"
#include "AudioChannel.h"

namespace nc
{
    bool AudioChannel::IsPlaying()
    {
        bool isPlaying = false;
        if (m_channel != nullptr)
        {
            //<call the method isPlaying() on m_channel, pass in the address of the bool isPlaying>
            m_channel->isPlaying(&isPlaying);
        }

        return isPlaying;
    }

    void AudioChannel::Stop()
    {
        if (IsPlaying())
        {
            m_channel->stop();
        }
    }
}

