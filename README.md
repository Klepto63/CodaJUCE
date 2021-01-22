# Coda JUCE Sandbox
- Généré à partir de Projucer V6.0.7 (14/01/21)
- Projet Visual Studio 2019 version 16.8.4

# Installation de git 
- download : https://git-scm.com/downloads
- setup tutorial  : https://learn.adafruit.com/windows-tools-for-the-electrical-engineer/git-plus-command-line-tools
- A la fin de l'installation (redémarrage), quand on fait clique droit sur le bureau, alors on voit apparaitre les onglet 'Git GUI here' et 'Git BASH Here'. Ca veut dire que l'installation est ok
- Pour cloner le repo en local : > git clone https://github.com/Klepto63/CodaJUCE.git

# Commande de base GIT : Créer et pousser une branche
- Se mettre sur la branche à partir de laquelle on veut partir, par exemple la branche 'master'  : 
>git checkout master
- Créer une branche locale :
>git checkout -b "nom_branch"
- Faire ses modifs / son code
- Pousser sa branche en locale puis sur le server :
> git add .
> git commit -m "commentaire concernant les modififications faites"
> git push 
Note : pour le premier push, il faut utiliser la commande affichée sur le terminal. Ensuite git push suffit.

# Commande de base GIT : Changer de branche
- Annuler d'eventuels modification sur la branche en cours :
> git stash
> git clean -xdf
- Changer de branche :
> git checkout "nom_branch_a_atteindre"
- Une fois arrivé sur la nouvelle branche, toujours faire un PULL pour récupérer d'eventuels mises à jour de la branche
> git pull

#
