#include "vsurface.h"

void play(GtkWidget *widget, gpointer data){
   snd_seq_t *seq = (snd_seq_t *)data;
   midi_action(seq, 60, 10);   
}


int main( int argc, char *argv[]) {
  GtkWidget *window;
  GtkWidget *frame;
  GtkWidget *plus;
   // Create midi input
  snd_seq_t *seq_handle = open_seq();
 
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Vsurface");
  gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
 

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame);

  plus = gtk_button_new_with_label("+");
  gtk_widget_set_size_request(plus, 80, 35);
  gtk_fixed_put(GTK_FIXED(frame), plus, 50, 20);


  gtk_widget_show_all(window);

  g_signal_connect(plus, "clicked", G_CALLBACK(play), seq_handle);


  g_signal_connect_swapped(G_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}
