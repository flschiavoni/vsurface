#include <alsa/asoundlib.h>
#include <gtk/gtk.h>

snd_seq_t *open_seq();
void midi_action(snd_seq_t *seq, int control, int value);

