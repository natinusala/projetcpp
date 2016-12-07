#ifndef FILETREEVIEW_HPP
#define FILETREEVIEW_HPP

#include <gtkmm.h>
#include "../../util/File.hpp"
#include "../Window.hpp"
#include "WidgetPerso.hpp"

 namespace khanar{

   class FileTreeView;

   class OngletFileObserver : public FileObserver
   {
   private:
     FileTreeView* _fileTreeView;

   public:
     OngletFileObserver(FileTreeView* fileTreeView) : _fileTreeView(fileTreeView)
     {}

     void fileUpdated(File* file) override;
   };

class FileTreeView : public ContentWidget
{
public:
  FileTreeView(Gtk::Window*& win,khanar::Window* wind, string path, bool recents);
  ~FileTreeView();
  Gtk::Box* getVbox();
  void reset();
  void reset(string filepath);
  void search(string search);
  string getPath();
  string getName();
protected:
  void on_button_quit();
  void on_button_press(GdkEventButton* button_event);
  void on_button_press_actu(const Gtk::TreeModel::Path& path,Gtk::TreeViewColumn* c);

  void on_terminal();
  void on_create_file();
  void on_delete_file();
  void on_create_directory();
  void on_rename();
  void on_cut();
  void on_copy();
  void on_paste();

  void on_sort_ascending();
  void on_sort_descending();
  void on_sort_name();
  void on_sort_size();
  void on_sort_date();

  OngletFileObserver fileObs = OngletFileObserver(this);

  Gtk::Window* parentWindow;
  khanar::Window* wind;
  Gtk::Menu menuPopup;
  File* f;
  vector<File>* subFiles;
  vector<File>* subFilesSearch;
  bool recents;


  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    {add(col_id); add(col_ico); add(col_name); add(col_number); }

    Gtk::TreeModelColumn<int> col_id;
    Gtk::TreeModelColumn<Glib::ustring> col_ico;
    Gtk::TreeModelColumn<Glib::ustring> col_name;
    Gtk::TreeModelColumn<Glib::ustring> col_number;
  };

  ModelColumns Columns;

  //Child widgets:
  Gtk::Box VBox;

  Gtk::ScrolledWindow scrolledWindow;
  Gtk::TreeView treeView;
  Glib::RefPtr<Gtk::ListStore> refTreeModel;
};
}
#endif