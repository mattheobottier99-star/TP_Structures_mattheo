#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Définition de la structure
typedef struct {
    int id;
    char nom[30];
    char ip[16];
    int est_actif; // 1 = Actif, 0 = Inactif
} Equipement;

// 2. Prototypes des fonctions
Equipement* allouer_parc(int nb_equipements);
void saisir_parc(Equipement* parc, int nb_equipements);
void afficher_parc(const Equipement* parc, int nb_equipements);
void changer_etat(Equipement* eq);

// 3. Programme principal
int main(void) {
    int n = 0;
    Equipement* mon_parc = NULL;

    printf("--- GESTION DU PARC RESEAU ---\n");
    printf("Combien d'equipements voulez-vous gerer ? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    // Allocation dynamique du parc
    mon_parc = allouer_parc(n);

    // Verification du pointeur (NULL ?)
    if (mon_parc == NULL) {
        return 1;
    }

    // Saisie des equipements
    saisir_parc(mon_parc, n);

    // Affichage du parc
    afficher_parc(mon_parc, n);

    // Changement d'etat du premier equipement
    printf("\nChangement d'etat du premier equipement...\n");
    changer_etat(&mon_parc[0]);
    printf("L'equipement %d est maintenant %s.\n", mon_parc[0].id, mon_parc[0].est_actif ? "ACTIF" : "INACTIF");

    // Liberation de la memoire
    free(mon_parc);
    mon_parc = NULL;

    printf("\nMemoire liberee avec succes.\n");
    return 0;
}

// --------------------------------------------------
// 4. Définitions des fonctions
// --------------------------------------------------

Equipement* allouer_parc(int nb_equipements) {
    Equipement* parc = (Equipement*)malloc(nb_equipements * sizeof(Equipement));
    return parc;
}

void saisir_parc(Equipement* parc, int nb_equipements) {
    for (int i = 0; i < nb_equipements; i++) {
        printf("--- Saisie de l'equipement %d ---\n", i + 1);

        printf("ID : ");
        scanf("%d", &parc[i].id);

        printf("Nom : ");
        scanf("%29s", parc[i].nom);

        printf("Adresse IP : ");
        scanf("%15s", parc[i].ip);

        printf("Actif (1: Oui, 0: Non) : ");
        scanf("%d", &parc[i].est_actif);
    }
}

void afficher_parc(const Equipement* parc, int nb_equipements) {
    printf("\n--- LISTE DES EQUIPEMENTS ---\n");
    for (int i = 0; i < nb_equipements; i++) {
        printf("ID: %d | Nom: %s | IP: %s | Etat: %s\n",
            parc[i].id,
            parc[i].nom,
            parc[i].ip,
            parc[i].est_actif ? "ACTIF" : "INACTIF");
    }
}

void changer_etat(Equipement* eq) {
    if (eq != NULL) {
        eq->est_actif = !eq->est_actif;
    }
}