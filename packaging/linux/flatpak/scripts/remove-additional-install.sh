#!/bin/sh

# User Service
systemctl --user stop sunshine
rm $HOME/.config/systemd/user/sunshine.service
systemctl --user daemon-reload
echo Sunshine User Service has been removed.

# Uhid loading
flatpak-spawn --host pkexec sh -c "rm /etc/modules-load.d/60-sunshine.conf"

# Udev rule
flatpak-spawn --host pkexec sh -c "rm /etc/udev/rules.d/60-sunshine.rules"
echo Mouse permission removed. Restart computer to take effect.
