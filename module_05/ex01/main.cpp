#include "Bureaucrate.hpp"
#include "Form.hpp"

int main(){
    //  init bureaucrate
    Bureaucrate bureaucrate;
    Bureaucrate bureaucrate2("Kevin", 100);
    Bureaucrate bureaucrate3("Bob", 150);
    Bureaucrate bureaucrate4("Paul", 1);
    Form        form("Form",75,75);

    //  first_test
    bureaucrate.signForm(form);
    bureaucrate2.signForm(form);
    bureaucrate3.signForm(form);
    bureaucrate4.signForm(form);
}