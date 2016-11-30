#include "vlc_core.h"

#pragma comment(lib,"libvlc")

void *pDrawable = NULL;

extern BufferingCallback gfpBufferingCallback;
extern EndedCallback gfpEndedCallback;

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
	pVLCMedia = libvlc_media_new_path(pVLCInstance, path);
	event_media_attach(pVLCMedia);
}

CoreAPI void CreateRemoteMedia(const char *url)
{
	pVLCMedia = libvlc_media_new_location(pVLCInstance, url);
	event_media_attach(pVLCMedia);
}

CoreAPI void Play()
{
	if (pVLCMediaPlayer == NULL)
	{
		pVLCMediaPlayer = libvlc_media_player_new_from_media(pVLCMedia);
		event_media_player_attach(pVLCMediaPlayer);
	}
	// 重新分配一个新的libvlc_media_t 指针
	libvlc_media_player_set_media(pVLCMediaPlayer, pVLCMedia);
	libvlc_media_player_set_hwnd(pVLCMediaPlayer, pDrawable);
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

CoreAPI void AttachBufferingCallback(BufferingCallback pBuffingCallback)
{
	gfpBufferingCallback = pBuffingCallback;
}
CoreAPI void AttachEndedCallback(EndedCallback pEndedCallback)
{
	gfpEndedCallback = pEndedCallback;
}









