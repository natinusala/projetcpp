#include <gtkmm.h>
#include <iostream>

#include "file/File.hpp"

using namespace khanar;
using namespace std;

//Fonctions/////////////////////////////////////////////////////////////

void on_button_clicked() {
	std::cout << "Bonjour" << std::endl;
	}

int main(int argc, char* argv[])
{
	Gtk::Main app(argc, argv);
	try
	{
		Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("/home/natinusala/khanar/assets/window.glade");
		Gtk::Window* win = nullptr;
		builder->get_widget("window1", cd .win);
		Gtk::Main::run(*win);
	}
	catch (Gtk::BuilderError err)
	{
		cout << err.what() << endl;
	}
}


//Fenêtre///////////////////////////////////////////////////////////////
int main2(int argc, char* argv[]) {
	Gtk::Main app(argc, argv);
	Gtk::Window fenetre;
	Gtk::VBox vb;

//Paramétrage

	fenetre.set_title("Ma belle fenetre!");
	fenetre.set_border_width(10);
	fenetre.add(vb);
	vb.show();
//Remplissage de la Verticale Box
	Gtk::Label l;
	vb.pack_start(l);
	l.show();
	Gtk::Entry e;
	vb.pack_start(e);
	e.show();

//Création d'un bouton
	Gtk::Button quitter(Gtk::Stock::QUIT);
	quitter.show();
	vb.pack_start(quitter);

//Création d'un second bouton
	Gtk::Button test(Gtk::Stock::OK);
	test.show();
	vb.pack_start(test);

//redimensionne la fenêtre
	fenetre.resize(480,480);

//Connexion des boutons aux signaux correspondants
	quitter.signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));

	test.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked));
//Ouverture de la fenêtre
	Gtk::Main::run(fenetre);
    return 0;
}
