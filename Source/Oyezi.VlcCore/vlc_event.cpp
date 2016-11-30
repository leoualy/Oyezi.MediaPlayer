#include "vlc_event.h"


void media_player_event_listener(const libvlc_event_t *pstEvent, void *value)
{
	extern BufferingCallback gfpBufferingCallback;
	int iEventType = pstEvent->type;
	switch (iEventType)
	{
		// 缓冲回调的处理
	case libvlc_MediaPlayerBuffering:
		if (gfpBufferingCallback != NULL)
		{
			gfpBufferingCallback(pstEvent->u.media_player_buffering.new_cache);
		}
		break;
	default:
		break;
	}
}

void media_event_listener(const libvlc_event_t *pstEvent, void *value)
{
	extern EndedCallback gfpEndedCallback;
	switch (pstEvent->u.media_state_changed.new_state)
	{
		// 处理视频播放结束的事件
	case libvlc_Ended:
		if (gfpEndedCallback != NULL)
		{
			// libvlc_media_release(pVLCMedia);
			// pVLCMedia = NULL;
			gfpEndedCallback();
		}
		break;
	default:
		break;
	}
}

void event_media_attach(libvlc_media_t *pstMedia)
{
	libvlc_event_manager_t *pstMediaEventManager = libvlc_media_event_manager(pstMedia);
	libvlc_event_attach(pstMediaEventManager, libvlc_MediaStateChanged, media_event_listener, NULL);
}

void event_media_player_attach(libvlc_media_player_t *pstMediaPlayer)
{
	libvlc_event_manager_t *pstMediaPlayerEventManager = libvlc_media_player_event_manager(pstMediaPlayer);
	libvlc_event_attach(pstMediaPlayerEventManager, libvlc_MediaPlayerBuffering, media_player_event_listener, NULL);
}