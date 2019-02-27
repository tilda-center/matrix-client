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

Fl_Hold_Browser *bro = 0;
Fl_Group *grp[3] = { 0,0,0 };

void SelectGroup_CB(Fl_Widget*, void*) {
    for ( int t=0; t<3; t++ ) {
        if ( t == (bro->value()-1) ) { grp[t]->show(); }
        else                         { grp[t]->hide(); }
    }
}

int main(int argc, char **argv)
{

  Fl_Window *window = new Fl_Window(570, 280);
  window->begin();
  {
    bro = new Fl_Hold_Browser(10,10,110,260);
    bro->add("Meka");
    bro->add("Dervish");

    grp[0] = new Fl_Group(130,10,430,260,"Mekanix");
    grp[0]->box(FL_ENGRAVED_BOX); grp[0]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP); grp[0]->labelsize(24);
        Fl_Text_Display *chat = new Fl_Text_Display(135,40,420,200);
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
        chat->buffer(*buff);
        buff->append("Mekanix: cao\n");
        buff->append("Momo: oj\n");
        new Fl_Input(210,245,300,20,"Message:");
        new Fl_Button(510,245,40,20,"Send");
    grp[0]->end();

    grp[1] = new Fl_Group(130,10,430,260,"Dervish");
    grp[1]->box(FL_ENGRAVED_BOX); grp[1]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP); grp[1]->labelsize(24);
        Fl_Text_Buffer *buff2 = new Fl_Text_Buffer();
        Fl_Text_Display *chat2 = new Fl_Text_Display(135,40,420,200);
        chat2->buffer(*buff2);
        buff2->append("Dervish: dolazite?\n");
        buff2->append("Momo: na putu :)\n");
        new Fl_Input(210,245,300,20,"Message:");
        new Fl_Button(510,245,40,20,"Send");
    grp[1]->end();

    grp[2] = new Fl_Group(130,10,430,260,"Dusan");
    grp[2]->box(FL_ENGRAVED_BOX); grp[2]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP); grp[2]->labelsize(24);
        new Fl_Text_Display(135,40,420,200);
        new Fl_Input(210,245,300,20,"Message:");
    grp[2]->end();

    bro->callback(SelectGroup_CB);
    bro->select(1);
    SelectGroup_CB(0,0);
  }
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
