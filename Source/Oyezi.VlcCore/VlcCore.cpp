#include "VlcCore.h"

#pragma comment(lib,"libvlc")

extern libvlc_event_manager_t *pVLCMediaPlayerEventManager;
extern libvlc_event_manager_t *pVLCMediaEventManager;

void *pDrawable = NULL;

CoreAPI int CreateVlcInstance()
{
	return (pVLCInstance = libvlc_new(0, NULL)) != NULL ? 0 : -1;
}

CoreAPI void SetDrawable(void *hwnd)
{
	pDrawable = hwnd;
}


CoreAPI void CreateLocalMedia(const char *path)
{
	if (pVLCMedia == NULL){
		pVLCMedia = libvlc_media_new_path(pVLCInstance, path);
		attach_media_events();
	}
}

CoreAPI void CreateRemoteMedia(const char *url)
{
	if (pVLCMedia == NULL){
		pVLCMedia = libvlc_media_new_location(pVLCInstance, url);
		attach_media_events();
	}
}

CoreAPI void Play()
{
	if (pVLCMediaPlayer == NULL)
	{
		pVLCMediaPlayer = libvlc_media_player_new_from_media(pVLCMedia);
		attach_media_player_events();
	}
	libvlc_media_player_set_hwnd(pVLCMediaPlayer, pDrawable);
	libvlc_media_player_set_position(pVLCMediaPlayer, 0.0);
	libvlc_media_player_play(pVLCMediaPlayer);
	
	return;
}

CoreAPI void Pause()
{
	libvlc_media_player_pause(pVLCMediaPlayer);
}

CoreAPI int Destory()
{
	libvlc_media_player_release(pVLCMediaPlayer);
	libvlc_media_release(pVLCMedia);
	libvlc_release(pVLCInstance);
	return 0;
}


void attach_media_events()
{
	pVLCMediaEventManager = libvlc_media_event_manager(pVLCMedia);
	libvlc_event_attach(pVLCMediaEventManager, libvlc_MediaStateChanged, OnVLCEventCallback, NULL);
}
void attach_media_player_events()
{
	pVLCMediaPlayerEventManager = libvlc_media_player_event_manager(pVLCMediaPlayer);
	libvlc_event_attach(pVLCMediaPlayerEventManager, libvlc_MediaPlayerBuffering, OnVLCEventCallback, NULL);
}








