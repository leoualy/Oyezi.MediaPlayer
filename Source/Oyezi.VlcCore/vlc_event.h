#ifndef VLC_H
#define VLC_H
#include <vlc\vlc.h>
#endif

#include "vlc_callback.h"

void event_media_attach(libvlc_media_t *pMedia);
void event_media_player_attach(libvlc_media_player_t *pMediaPlayer);