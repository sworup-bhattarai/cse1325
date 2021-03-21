#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <vector>
#include "person.h"
#include "parent.h"
#include "student.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_school_click();          // Create a new school 
        void on_new_student_click();       
        void on_new_parents_click();     
        void on_quit_click();		     // Exit the game
        void on_student_to_parent_click();              
    private:
	std::vector<Student> student;
	std::vector<Parent> parent;
    Gtk::Label *display;                      // Display of sticks on game board
    void show_data();

};
#endif 

