# Network Recon with Nmap

This lab will teach you how to use **nmap** to perform network reconnaissance.  
By the end, you will know how to:
- Discover active devices on your subnet
- Identify what services/devices are running
- Group devices by type (router, IoT, laptop, etc.)
- Perform stealthier scans
- Compete with your classmates in recon challenges

---

## 🚀 Getting Started

Make sure you have `nmap` installed. On most systems:

```bash
# Linux (Debian/Ubuntu)
sudo apt install nmap

# Mac (Homebrew)
brew install nmap

# Windows (Download installer)
https://nmap.org/download.html
```

Check your version:
```bash
nmap --version
```

---

## 🔎 Step 1: Scan Your Subnet

Most classroom networks are `/24` (e.g., `192.168.8.0/24`) which means **255 devices possible**.

### Basic host discovery (no ping):
```bash
nmap -Pn 192.168.8.0/24
```

### Faster host discovery (ping scan only):
```bash
nmap -sn 192.168.8.0/24
```

### Include MAC addresses (requires sudo):
```bash
sudo nmap -sn 192.168.8.0/24
```

---

## 🧩 Step 2: Identify and Group Devices

Look at:
- **IP addresses**: some may be routers or DHCP servers
- **MAC vendors**: tells you manufacturer (Apple, Cisco, HP, Xiaomi)
- **Hostnames**: may reveal device type

Group into:
- Infrastructure (router, switches, firewall)
- User devices (PCs, laptops, phones)
- IoT (cameras, smart TVs, printers)
- Servers (multiple open services)

---

## 🛠 Step 3: Service Enumeration

After finding interesting hosts, dig deeper.

### Find services & versions:
```bash
nmap -sV 192.168.8.100
```

### Run default scripts + version detection:
```bash
nmap -sC -sV 192.168.8.100
```

### Scan all 65,535 ports:
```bash
nmap -p- -sV 192.168.8.100
```

---

## 🕵️ Step 4: Silent Hunter (Stealth Scans)

Scanning can be **noisy**. Try being stealthier.

### Add scan delay:
```bash
nmap -sS --scan-delay 1s 192.168.8.100
```

### Limit to top ports:
```bash
nmap --top-ports 20 192.168.8.100
```

### Randomize host order:
```bash
nmap -sS --randomize-hosts 192.168.8.0/24
```

---

## 🏆 Competitive Activities

### 1. Host Discovery Race
- First team to list all active IPs on the subnet.

### 2. Hidden Device Hunt
- Find the device that doesn’t respond to ping but has open ports.

### 3. Router Model ID
- First to correctly identify the router’s make/model.

### 4. IoT Device Challenge
- Correctly identify an IoT device (camera, TV, printer, etc.).

### 5. OS Guess
- Most accurate OS guess using:
```bash
nmap -O 192.168.8.100
```

### 6. Vendor Bingo
- Collect points for each unique MAC vendor identified.

### 7. Service Banner Jackpot
- First to capture a service banner (e.g., “Apache httpd 2.4.41”).

### 8. Odd Service Award
- Points for finding the most unusual open port.

### 9. Full Service Map
- Build a complete table of IPs vs services.

### 10. Peer Recon – Who’s Who?
- Match IPs to classmates’ devices.
- Bonus for OS guess, hostname, or service fingerprint.

### 11. Subnet Social Graph
- Build a diagram of all peers with IP, OS guess, and device type.

### 12. Silent Hunter
- Demonstrate a stealth scan that finds services with minimal noise.

---

## ✅ Useful Command Reference

```bash
# Subnet scan without ping
nmap -Pn 192.168.8.0/24

# Ping sweep only
nmap -sn 192.168.8.0/24

# Service version detection
nmap -sV 192.168.8.100

# Default scripts + services
nmap -sC -sV 192.168.8.100

# All ports
nmap -p- -sV 192.168.8.100

# OS detection
nmap -O 192.168.8.100

# Stealthier scan
nmap -sS --scan-delay 1s 192.168.8.100
```

---

**Happy Hunting!**  
