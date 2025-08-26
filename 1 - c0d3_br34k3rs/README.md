# Cryptography Labs

This repository contains two educational Jupyter/Colab notebooks designed to teach the fundamentals of cryptography through hands-on simulations and coding exercises.

## Included Labs

1. **Caesar Cipher Brute Force Lab**  
   - Demonstrates the basics of substitution ciphers using the Caesar cipher.  
   - Students can encode and decode text, then use a brute-force approach to break ciphers created by a Caesar wheel.  
   - Highlights the weaknesses of simple classical ciphers and why stronger methods are necessary.  

2. **Public/Private Key Cryptography Lab**  
   - Introduces the principles of asymmetric cryptography.  
   - Includes an implementation of the Diffie–Hellman key exchange to demonstrate secure key establishment.  
   - Walks through toy RSA examples (encrypt/decrypt and sign/verify).  
   - Shows how hybrid cryptography (combining symmetric and asymmetric) underpins secure internet protocols such as TLS/HTTPS.  

## General Approach

- Each notebook is structured with **Setup**, **Inputs**, **Simulator/Code**, and **Results**.  
- Students are encouraged to adjust variables and re-run cells to deepen understanding.  
- Explanations and code work together to provide both **conceptual clarity** and **practical reinforcement**.  

---

## Suggested One-Shot Prompts

You can recreate these notebooks yourself by using prompts like the following:

### Caesar Cipher Notebook

```
I want to create a Colab-ready Jupyter notebook that teaches the Caesar cipher. 
The notebook should:
- Explain how the Caesar cipher works. 
- Allow encoding and decoding of text with a given shift. 
- Include a brute-force tool that tries all possible shifts to break a cipher automatically. 
- Show examples with user-provided text. 
- Be structured with clear sections for Setup, Encode/Decode, Brute Force, and Student Exercises.
```

### Public/Private Key Cryptography Notebook

```
I want to create a Colab-ready Jupyter notebook that introduces public/private key cryptography. 
The notebook should:
- Demonstrate the Diffie–Hellman key exchange. 
- Include toy RSA examples for encryption/decryption and signing/verifying. 
- Show how hybrid cryptography combines symmetric and asymmetric methods. 
- Highlight how these ideas enable the secure internet (TLS/HTTPS). 
- Be structured with clear sections for Setup, Key Exchange, RSA, Hybrid Example, and Exercises.
```

---

These labs are meant to give students both the **aha moment** of breaking weak ciphers and the **appreciation** of how modern cryptography secures communication today.
