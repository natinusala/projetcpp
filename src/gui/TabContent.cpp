
#include "TabContent.hpp"


#include "../compiled_assets/topbar.glade.hex"
#include "../compiled_assets/propertiesbar.glade.hex"
#include "../compiled_assets/vboxlayout.glade.hex"

namespace khanar{
    TabContent::TabContent(){
        this->_builder = Assets::buildGtkFromResource(topbar_glade);
    }

    TabContent::TabContent(Gtk::Widget *widget){
        this->_builder = Assets::buildGtkFromResource(topbar_glade);
    }

    Gtk::Box* TabContent::getContent(Gtk::Widget *widget){
        Gtk::Box* add = nullptr;
        Gtk::Box* container = nullptr;

        this->_builder->get_widget("box3",container);
        this->_builder->get_widget("box1",add);
        widget->show_all();
        container->pack_start(*widget);
        container->reorder_child(*widget,0);
        return add;
  }
  void TabContent::setPropBar(File f){

    Gtk::Label* nom = nullptr;
    Gtk::Label* type = nullptr;
    Gtk::Label* taill = nullptr;
    Gtk::Label* acces = nullptr;
    Gtk::Label* modifie = nullptr;
    Gtk::Label* nomProprio = nullptr;
    this->_builder->get_widget("nom",nom);
    this->_builder->get_widget("type",type);
    this->_builder->get_widget("taill",taill);
    this->_builder->get_widget("acces",acces);
    this->_builder->get_widget("modifie",modifie);
    this->_builder->get_widget("nomProprietaire",nomProprio);
    nom->set_text(f.getName());
    type->set_text(f.getFileType().getName());
    taill->set_text(to_string(f.getSize()/1000)+"ko");
    char buffer [50];
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,20,"%d/%m/%y",timeinfo);
    char acc [50]= "Accédé : ";
    char result[100];
    strcpy(result,acc);
    strcat(result,buffer);
    acces->set_text(result);
  }
}
