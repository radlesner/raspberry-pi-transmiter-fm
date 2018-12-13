#bin/bash

echo "Positional Parameters"
echo '$1 = ' $1

sox -t mp3 $1 -t wav - | sudo src/binaries/pi_fm_rds -freq 107.9 -audio -
