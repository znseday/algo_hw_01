#include "itask.h"
#include "tester.h"

#include "stringlength.h"
#include "tickets.h"

using namespace std;
namespace fs = std::experimental::filesystem;

int main()
{
    StringLength stringLength;
    ITask &taskString = stringLength;
    Tester testerString(taskString, fs::current_path().string() + "\\0.String");

    cout << "Task String:" << endl;
    testerString.RunTests();

    cout << endl << "Task Tickets:" << endl;
    Tickets tickets;
    ITask &taskTickets = tickets;
    Tester testerTickets(taskTickets, fs::current_path().string() + "\\1.Tickets");

//    testerTickets.SetShowExpects(true);
//    testerTickets.SetShowActuals(true);
    testerTickets.SetShowTime(true);
    testerTickets.RunTests();

    return 0;
}
