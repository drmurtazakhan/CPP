// Suggested file name: qt_simple_button.cpp
// compile: g++ -std=c++17 qt_simple_button.cpp -o qt_simple_button.exe -I C:/msys64/ucrt64/include/qt6 -I C:/msys64/ucrt64/include/qt6/QtWidgets -I C:/msys64/ucrt64/include/qt6/QtCore -I C:/msys64/ucrt64/include/qt6/QtGui -L C:/msys64/ucrt64/lib -lQt6Widgets -lQt6Gui -lQt6Core
// run: .\qt_simple_button.exe

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    // Initialize the Qt application object
    QApplication app(argc, argv);

    // Create a button widget
    QPushButton button("Click me to exit!");
    button.resize(200, 100);
    button.show();

    // Connect the button's clicked signal to the application's quit slot
    QObject::connect(&button, &QPushButton::clicked, &app, &QApplication::quit);

    // Start the event loop
    return app.exec();
}