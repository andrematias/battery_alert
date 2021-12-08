# Battery Alert

A simple battery monitor to mackbook pro (late 2012) to get notice when is
extremally lower.

## Targets

1 - Read system file on `/sys/class/power_supply/BAT0/capacity` to get battery
percentage.

2 - If it is less then 10% send a notification using `notice-send` binary
