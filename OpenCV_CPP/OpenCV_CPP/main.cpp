//Name des selbst erstellten Formularfensters austauschen
#include "Hauptfenster.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Name des eigenen Projekts und Formulars ersetzen 
	OpenCVCPP::Hauptfenster^ fenster1 = gcnew OpenCVCPP::Hauptfenster;

	//Anwendung soll mit Fenster 1 starten
	Application::Run(fenster1);
}
