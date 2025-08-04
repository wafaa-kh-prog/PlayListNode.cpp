// ConsoleApplication337.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* next;
};

//This is a function to add a song to the playlist
void addSong(Song*& head, const string& songName) {
    Song* newSong = new Song{ songName, NULL };

    if (head == NULL) {
        head = newSong;
    }
    else {
        Song* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newSong;
    }
    cout << " Song added: " << songName << endl;
}

//This function is used to show every track stored in the linked list
void displayPlaylist(Song* head) {
    if (head == NULL) {
        cout << " Playlist is empty \n";
        return;
    }

    cout << "\n Current Playlist:\n";
    Song* p = head;
    int i;
    i = 1;
    while (p != NULL) {
        cout << i++ << ". " << p->name << endl;
        p = p->next;
    }
}

//This function outputs the title of the current song being played
void playCurrent(Song* p) {
    if (p == NULL) {
        cout << " No song to play \n";
    }
    else {
        cout << " Now Playing: " << p->name << endl;
    }
}

// The function moves the pointer to the next song in the playlist and plays it
Song* playNext(Song* p) {
    if (p == NULL || p->next == NULL) {
        cout << " No next song\n";
        return p;
    }
    else {
        p = p->next;
        playCurrent(p);
        return p;
    }
}

// The function searches for a song by name and deletes it from the linked list
void removeSong(Song*& head, const string& songName) {
    if (head == NULL) {
        cout << " Song not found\n";
        return;
    }

    if (head->name == songName) {
        Song* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << " Song deleted: " << songName << endl;
        return;
    }

    Song* p = head;
    while (p->next != NULL && p->next->name != songName) {
        p = p->next;
    }

    if (p->next != NULL) {
        Song* toDelete = p->next;
        p->next = p->next->next;
        delete toDelete;
        cout << " Song deleted: " << songName << endl;
    }
    else {
        cout << " Song not found\n";
    }
}
int main() {
    Song* playlist = NULL;
    Song* currentSong = NULL;
    int choice;
    string name;

    while (true) {
        cout << "\n Music Player Menu \n";
        cout << "1. Add song\n";
        cout << "2. Show playlist\n";
        cout << "3. Play current song\n";
        cout << "4. Next song\n";
        cout << "5. Remove song\n";
        cout << "6. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter song name: ";
            getline(cin, name);
            addSong(playlist, name);
            if (currentSong == NULL)
                currentSong = playlist;

        }
        else if (choice == 2) {
            displayPlaylist(playlist);

        }
        else if (choice == 3) {
            playCurrent(currentSong);

        }
        else if (choice == 4) {
            currentSong = playNext(currentSong);

        }
        else if (choice == 5) {
            cout << "Enter song name to remove: ";
            getline(cin, name);
            bool isCurrent = (currentSong && currentSong->name == name);
            removeSong(playlist, name);
            if (isCurrent) {
                currentSong = playlist; 
            }
        }
        else if (choice == 6) {
            cout << " Exiting music player Bye! \n";
            break;

        }
        else {
            cout << " Invalid option \n";
        }
    }
    return 0;
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
