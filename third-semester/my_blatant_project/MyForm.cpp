#include "MyForm.h"
//#include "LR_8_1.h"
#include <Windows.h> 
using namespace myblatantproject; // Название проекта 

[STAThread]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
