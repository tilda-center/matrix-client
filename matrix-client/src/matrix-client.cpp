#include <FL/Fl.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <arpa/inet.h>
#include <iostream>
#include <tuple>
#include <string>


typedef std::tuple<Fl_Group *, Fl_Text_Buffer *, Fl_Input *> Params;


Fl_Group *oldSelected = nullptr;
Fl_Hold_Browser *bro = nullptr;


void SelectGroup_CB(Fl_Widget *w, void*) {
  if (oldSelected != nullptr)
  {
    oldSelected->hide();
  }
  int line = bro->value();
  if (line)
  {
    Params *p = (Params *)bro->data(line);
    auto group = std::get<0>(*p);
    group->show();
    oldSelected = group;
  }
}


void sendMessage(Fl_Widget *w, void *v)
{
  Params *p = (Params *)v;
  auto buffer = std::get<1>(*p);
  auto input = std::get<2>(*p);
  buffer->append(input->value());
  buffer->append("\n");
  input->value("");
  input->take_focus();
}


int main(int argc, char **argv)
{

  Fl_Window *window = new Fl_Window(570, 280);
  window->begin();
  {
    bro = new Fl_Hold_Browser(10,10,110,260);

    Fl_Group *group = new Fl_Group(130,10,430,260,"Mekanix");
    group->box(FL_ENGRAVED_BOX);
    group->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP);
    group->labelsize(24);
    group->begin();
    {
        Fl_Text_Display *chat = new Fl_Text_Display(135,40,420,200);
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
        chat->buffer(*buff);
        buff->append("Mekanix: cao\n");
        buff->append("Momo: oj\n");
        Fl_Input *input = new Fl_Input(210,245,300,20,"Message:");
        input->take_focus();
        Fl_Button *button = new Fl_Button(510,245,40,20,"Send");
        Params *p = new Params;
        (*p) = std::make_tuple(group, buff, input);
        bro->add("Meka", p);
        button->callback(sendMessage, p);
        button->shortcut(FL_Enter);
    }
    group->end();
    group->show();

    group = new Fl_Group(130, 10, 430, 260, "Dervish");
    group->box(FL_ENGRAVED_BOX);
    group->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP);
    group->labelsize(24);
    group->begin();
    {
        Fl_Text_Display *chat = new Fl_Text_Display(135,40,420,200);
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
        chat->buffer(*buff);
        buff->append("Dervish: cao\n");
        buff->append("Momo: oj\n");
        Fl_Input *input = new Fl_Input(210,245,300,20,"Message:");
        input->take_focus();
        Fl_Button *button = new Fl_Button(510,245,40,20,"Send");
        Params *p = new Params;
        (*p) = std::make_tuple(group, buff, input);
        bro->add("Dervish", p);
        button->callback(sendMessage, p);
        button->shortcut(FL_Enter);
    }
    group->end();
    group->hide();
    bro->callback(SelectGroup_CB);
    bro->select(1);
    SelectGroup_CB(0, 0);
  }
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
