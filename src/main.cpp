#include <windows.h>
#include "Core/GameEngine.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(65001);
    
    // 🎲 Initialisation de l'aléatoire
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    std::cout << "🎮 Demarrage du Simulateur d'Ecosysteme" << std::endl;
    std::cout << "=======================================" << std::endl;
    
    // 🏗 Création du moteur de jeu
    Ecosystem::Core::GameEngine engine("Simulateur d'Ecosystème Intelligent", 1200.0f, 800.0f);
    
    // ⚙️ Initialisation
    if (!engine.Initialize()) {
        std::cerr << "Erreur: Impossible d'initialiser le moteur de jeu" << std::endl;
        return -1;
    }
    
    std::cout << "Moteur initialise avec succes" << std::endl;
    std::cout << "Lancement de la simulation..." << std::endl;
    std::cout << "=== CONTROLES ===" << std::endl;
    std::cout << "ESPACE: Pause/Reprise" << std::endl;
    std::cout << "R: Reset simulation" << std::endl;
    std::cout << "F: Ajouter nourriture" << std::endl;
    std::cout << "FLECHES: Vitesse simulation" << std::endl;
    std::cout << "ECHAP: Quitter" << std::endl;
    
    // 🎮 Boucle principale
    engine.Run();
    
    // 🛑 Arrêt propre
    engine.Shutdown();
    
    std::cout << "Simulation terminee. Appuyez sur entree pour fermer..." << std::endl;
    return 0;
}