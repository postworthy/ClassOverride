Juice Shop Lab (Tailscale-only) — Multi-team Docker Compose
========================================================

What this does
--------------
- Runs OWASP Juice Shop (bkimminich/juice-shop) in multiple instances (replicas).
- Each replica listens on container port 3000.
- Docker publishes those to host ports 3000..3099 **but only bound to the host's Tailscale IP**.
- Result: reachable from other devices on your tailnet, not from the wider LAN/Internet (assuming normal routing).

Files
-----
- compose.yml            : main Docker Compose config
- .env (generated)       : contains TS_IP=<your tailscale IPv4>
- scripts/gen-env.sh     : generates .env from `tailscale ip -4`
- scripts/up.sh          : start N instances (default N=4)
- scripts/down.sh        : stop everything
- scripts/status.sh      : show running containers
- scripts/ufw-lockdown.sh: OPTIONAL extra host firewall tightening (Ubuntu/Debian with UFW)

Prereqs
-------
- Docker + Docker Compose plugin installed (`docker compose version`)
- Tailscale installed and connected (`tailscale status`)

Quick start (4 teams)
---------------------
1) Generate .env (or let up.sh do it):
   ./scripts/gen-env.sh

2) Start 4 instances:
   ./scripts/up.sh 4

3) Give teams these URLs:
   http://<TS_IP>:3000
   http://<TS_IP>:3001
   http://<TS_IP>:3002
   http://<TS_IP>:3003

Scale up later
--------------
- Start 10 teams:
  ./scripts/up.sh 10

Port planning
-------------
- The compose file reserves host ports 3000-3099 (up to 100 teams).
- Increase the range if you need more.

Optional: extra host firewall safety (recommended)
--------------------------------------------------
If you're on Ubuntu/Debian and want to make *extra sure* only tailscale can hit these ports:

  ./scripts/ufw-lockdown.sh

Troubleshooting
---------------
- "bind: address already in use": another service is using those ports; change the range in compose.yml.
- "TS_IP is empty": ensure tailscaled is running and you're connected to your tailnet.
- Test from another tailnet device:
  curl -I http://<TS_IP>:3000
