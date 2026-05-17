
#include <QApplication>
#include "MainWindow.h"

// ------------------------------------------------------------------
// main() is the very first function that runs when you start the app.
// Think of it as the "front door" of your program — everything begins here.
// ------------------------------------------------------------------
int main(int argc, char *argv[])
{
    // QApplication is a special Qt object that starts up the whole program.
    // It reads any command-line arguments (argc, argv) and gets Qt ready to run.
    // Every Qt app needs exactly one of these — it's like turning on the engine
    // before you can drive the car.
    QApplication app(argc, argv);

    // Here we create an OBJECT called "window" from our MainWindow CLASS.
    // A class is like a blueprint, and an object is the actual thing built from it.
    // This one line builds the entire window with all its buttons and labels.
    MainWindow window;
    
    // This tells Qt to make the window visible on screen.
    // Without this line, the window would be created but never shown.
    window.show();

    // app.exec() starts the EVENT LOOP.
    // An event loop is like a security guard that sits and waits —
    // when the user clicks a button or types something, it notices and reacts.
    // The program stays inside this loop until the user closes the window.
    // When the window closes, exec() returns and the program ends.
    return app.exec();
}
