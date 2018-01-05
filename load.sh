#!/bin/bash
echo -n "Buongiorno "; whoami
echo "Il sistema verrà aggiornato";

sleep 3

sudo apt update
sudo apt upgrade
