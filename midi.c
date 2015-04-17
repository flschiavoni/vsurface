#include "vsurface.h"

snd_seq_t *open_seq() {

  snd_seq_t *seq_handle;
  int portid;

  if (snd_seq_open(&seq_handle, "hw", SND_SEQ_OPEN_OUTPUT, 0) < 0) {
    fprintf(stderr, "Error opening ALSA sequencer.\n");
    exit(1);
  }

   if(snd_seq_set_client_name(seq_handle, "vsurface") < 0){
      printf("Could not set client name");
   }

  if ((portid = snd_seq_create_simple_port(seq_handle, "vsurface",
            SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
            SND_SEQ_PORT_TYPE_APPLICATION)) < 0) {
    fprintf(stderr, "Error creating sequencer port.\n");
    exit(1);
  }

   printf("portid: %d\n", portid);
  return(seq_handle);
}

void midi_action(snd_seq_t *seq, int control, int value){
   snd_seq_event_t ev;

   snd_seq_ev_clear(&ev);
   snd_seq_ev_set_source(&ev, 0);
   snd_seq_ev_set_subs(&ev);
   snd_seq_ev_set_direct(&ev);

   ev.type = SND_SEQ_EVENT_CONTROLLER;
   ev.data.control.channel = 0;
   ev.data.control.param = control;
   ev.data.control.value = value;


   snd_seq_event_output(seq, &ev);
   snd_seq_drain_output(seq);
}
