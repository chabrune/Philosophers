# 🧠 Philosophers - Simulation de Dîner des Philosophes

Une implémentation du problème classique de synchronisation des philosophes utilisant des threads et des mutex.

## 📝 Description

Le projet simule des philosophes assis autour d'une table qui alternent entre manger, penser et dormir, tout en partageant des ressources limitées (fourchettes).

## 🛠️ Fonctionnalités

### Paramètres du Programme
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Actions des Philosophes
- Manger (nécessite 2 fourchettes)
- Dormir
- Penser
- Mourir (si ne mange pas à temps)

## ⚙️ Spécifications Techniques

### Gestion des Ressources
- Un thread par philosophe
- Un mutex par fourchette
- Synchronisation précise des actions
- Pas de data races
- Pas de variables globales

### Format des Messages
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## 🌟 Bonus
- Version avec processus au lieu de threads
- Utilisation de sémaphores au lieu de mutex
- Fourchettes au centre de la table

## ⚠️ Contraintes
- Message de mort < 10ms après décès
- Gestion précise du temps
- Protection contre les data races
- Libération propre des ressources

---
*Projet réalisé dans le cadre du cursus de l'école 42* 

