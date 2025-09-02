# 🔐 OWASP Top 10 x Juice Shop Guide

## 🌍 What is OWASP?
The **Open Worldwide Application Security Project (OWASP)** is a global non-profit focused on improving software security. Since 2003, OWASP has published the **Top 10**, a regularly updated awareness document that highlights the most critical web application security risks.

## 🍊 What is Juice Shop?
**OWASP Juice Shop** is a deliberately insecure e-commerce app packed with vulnerabilities covering the OWASP Top 10 and more. It looks like a real online shop but is built to be hacked, making it a perfect lab for security learners.

## ⚙️ Quick Setup Guide
Run Juice Shop locally with Node.js:

```bash
# Install Node.js first
git clone https://github.com/juice-shop/juice-shop.git --depth 1
cd juice-shop
npm install
npm start
```

Visit: 👉 [http://localhost:3000](http://localhost:3000)

---

# 🕵️ The OWASP Top 10 in Juice Shop

Below you’ll find **each OWASP Top 10 item** explained with a **practical Juice Shop challenge** you can try.

---

### **A01:2021 – Broken Access Control**
🔑 *When users can act outside their intended permissions.*

**Juice Shop Example:** *View another user’s shopping basket*.
- Log in as a normal user.
- Intercept the request to `/rest/basket/{id}` with DevTools or Burp.
- Change the basket ID to another user’s.
- You’ll see their shopping cart data, proving access control is broken.

---

### **A02:2021 – Cryptographic Failures**
🔑 *Sensitive data exposure due to weak or missing crypto.*

**Juice Shop Example:** *Forge a coupon code*.
- Find how coupons are generated (hint: look at Twitter/backup files).
- Recreate or brute-force a valid coupon code.
- Redeem it in the basket to get a massive discount.

---

### **A03:2021 – Injection**
🔑 *Untrusted data is executed as code (SQL, NoSQL, XSS, etc).*

**Juice Shop Example:** *Track order SQL/NoSQL injection*.
- Go to “Track Orders” and enter `' || true || '` as Order ID.
- The app will return **all orders** from the database.

---

### **A04:2021 – Insecure Design**
🔑 *Flaws in the system’s design, not just coding mistakes.*

**Juice Shop Example:** *Obfuscated email collision*.
- Place an order as `admin@juice-sh.op`.
- Notice emails get vowels replaced with `*`.
- Register `edmin@juice-sh.op` → both resolve to `*dm*n@j**c*-sh.*p`.
- Data export shows you **admin’s order history** – a design flaw.

---

### **A05:2021 – Security Misconfiguration**
🔑 *Default, incomplete, or ad-hoc configurations create risks.*

**Juice Shop Example:** *Access developer backup file*.
- Visit `http://localhost:3000/ftp/` to explore exposed files.
- Use a poison null byte trick (`%2500`) to download `.yml` or `.adoc` files.
- These contain sensitive system data.

---

### **A06:2021 – Vulnerable and Outdated Components**
🔑 *Using old, vulnerable dependencies.*

**Juice Shop Example:** *Check `/package.json` in source*.
- Juice Shop intentionally uses outdated libraries (like Express versions with known CVEs).
- In practice, run `npm audit` in your cloned repo to see the long list of vulnerable modules.

---

### **A07:2021 – Identification and Authentication Failures**
🔑 *Weak login, password recovery, or session flaws.*

**Juice Shop Example:** *Reset Bender’s password*.
- Use “Forgot Password?” for `bender@juice-sh.op`.
- Correctly guess/lookup his security question.
- Reset and log in as Bender without knowing the old password.

---

### **A08:2021 – Software and Data Integrity Failures**
🔑 *Untrusted code, updates, or deserialization issues.*

**Juice Shop Example:** *Abuse insecure JSON deserialization*.
- Open Swagger at [http://localhost:3000/api-docs](http://localhost:3000/api-docs).
- Auth as a user, then POST:
```json
{"orderLinesData": "(function dos() { while(true); })()"}
```
- The app tries to execute it, hitting infinite loop protection.

---

### **A09:2021 – Security Logging and Monitoring Failures**
🔑 *Lack of detection and response capabilities.*

**Juice Shop Example:** *Access exposed Prometheus metrics*.
- Visit `http://localhost:3000/metrics`.
- You’ll see Prometheus data (users, traffic, cheat detection).
- In a real app, exposing this would give attackers insights with no alerting.

---

### **A10:2021 – Server-Side Request Forgery (SSRF)**
🔑 *When the server makes requests to attacker-chosen URLs.*

**Juice Shop Example:** *SSRF challenge*.
- The app lets you request remote resources.
- Point it at internal services (`http://localhost:3000/ftp/...`) or cloud metadata endpoints.
- You retrieve hidden files/resources through the server.

---

# 🎯 Final Notes
- Every challenge you complete triggers **confetti & notifications** 🎉.
- Use browser DevTools, intercepting proxies (Burp/ZAP), and the source code for deeper insights.
- Juice Shop isn’t just about finding bugs—it’s about **understanding why they exist** and how to prevent them.

---

### 🔗 References
- OWASP Top 10: [https://owasp.org/www-project-top-ten/](https://owasp.org/www-project-top-ten/)
- OWASP Juice Shop: [https://github.com/juice-shop/juice-shop](https://github.com/juice-shop/juice-shop)
- Juice Shop Guidebook: [https://pwning.owasp-juice.shop](https://pwning.owasp-juice.shop)
