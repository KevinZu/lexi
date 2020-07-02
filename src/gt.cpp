#include <stdio.h>
#include <gtk/gtk.h>
void gtest(int a)
{
	printf("===:%d\n",a);
}



static void
draw_round_rectangle (cairo_t * cr,
                      double x, double y,
                      double width, double height, double r)
{
	cairo_move_to (cr, x + r, y);
	cairo_line_to (cr, x + width - r, y);

	cairo_move_to (cr, x + width, y + r);
	cairo_line_to (cr, x + width, y + height - r);

	cairo_move_to (cr, x + width - r, y + height);
	cairo_line_to (cr, x + r, y + height);

	cairo_move_to (cr, x, y + height - r);
	cairo_line_to (cr, x, y + r);

	cairo_arc (cr, x + r, y + r, r, 3.14, 3 * 3.14 / 2.0);
	cairo_arc (cr, x + width - r, y + r, r, 3 * 3.14 / 2, 2 * 3.14);
	cairo_arc (cr, x + width - r, y + height - r, r, 0, 3.14 / 2);
	cairo_arc (cr, x + r, y + height - r, r, 3.14 / 2, 3.14);
}

static gboolean
draw (GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
	cr = gdk_cairo_create (gtk_widget_get_window (widget));

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_set_line_width (cr, 1);
	cairo_rectangle (cr, 20, 20, 120, 80);
	cairo_rectangle (cr, 180, 20, 80, 80);
	cairo_stroke_preserve (cr);
	cairo_set_source_rgb (cr, 1, 1, 1);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_arc (cr, 330, 60, 40, 0, 2 * 3.14);
	cairo_stroke_preserve (cr);
	cairo_set_source_rgb (cr, 1, 1, 1);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_arc (cr, 90, 160, 40, 3.14 / 4, 3.14);
	cairo_close_path (cr);
	cairo_stroke_preserve(cr);
	cairo_set_source_rgb (cr, 1, 1, 1);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, 0, 0, 0);
	cairo_translate (cr, 220, 180);
	cairo_scale (cr, 1, 0.7);
	cairo_arc (cr, 0, 0, 50, 0, 2 * 3.14);
	cairo_stroke_preserve (cr);
	cairo_set_source_rgb (cr, 1, 1, 1);
	cairo_fill (cr);

	cairo_set_source_rgb (cr, 0.8, 0.4, 0);
	cairo_translate (cr, 80, -30);
	cairo_set_line_width (cr, 6);
	draw_round_rectangle (cr, 5, 5, 60, 60, 8);
	cairo_stroke_preserve (cr);
	cairo_set_source_rgb (cr, 0.8, 0.8, 0.2);
	cairo_fill (cr);

	cairo_destroy (cr);

	return FALSE;
}

int gt( int argc, char **argv)
{
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new ();
	gtk_container_add (GTK_CONTAINER (window), darea);

	g_signal_connect (darea, "draw",
                      G_CALLBACK (draw), NULL);
	g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);

	gtk_window_set_position (GTK_WINDOW (window),
                             GTK_WIN_POS_CENTER);
	gtk_window_set_default_size (GTK_WINDOW (window), 500, 400);

	gtk_widget_show_all (window);

	gtk_main ();

	return 0;
}


