# Compound Interest + Frugality Labs

This repository contains Jupyter/Colab notebooks that demonstrate the long-term effects of **compound interest** and the power of **frugality**.  

## General Approach

Each notebook follows the same structure:

1. **Setup & Presets**  
   - Define a starting salary (based on a career field or a generic median).  
   - Add assumptions like contribution percentage, expected annual return, and annual raises.  
   - Include common “spending leaks” (e.g., coffee, dining out, streaming services) that can be redirected into investments.  

2. **Inputs (Editable)**  
   - Students can adjust career starting salary, contribution rates, cadence (weekly, monthly, yearly), return assumptions, and frugality settings.  
   - Inflation is ignored in these models to highlight the raw power of compounding.  

3. **Simulator**  
   - Year-by-year calculation of salary, contributions, redirected spending, and final portfolio balance.  
   - Simulations are run both for a **Base Plan** (income % only) and a **Frugality Plan** (base + redirected leaks).  

4. **Outputs**  
   - Tables that show annual salary, contributions, and balances.  
   - Charts comparing base vs. frugality outcomes and illustrating contributions vs. compound growth.  
   - Key takeaways on how small, consistent choices lead to large long-term differences.  

This methodology allows students to see how different careers and personal finance habits shape wealth trajectories over 30 years or more.

---

## Suggested Prompt for Students

If you’d like to create a new notebook for a career of your choice, you can use the following prompt:

```
I want to create a Colab-ready Jupyter notebook that demonstrates the power of compound interest for someone starting a career as a [CAREER TITLE]. 

The notebook should:
- Use the typical starting salary for that profession (include a citation/link to the data source).  
- Assume best-case investment returns by default (e.g., 10% annually), but make it adjustable.  
- Include inputs for contribution % of income, annual raises, and cadence (weekly, monthly, yearly).  
- Add common “spending leaks” like coffee, dining out, streaming, ride-hailing, or energy drinks, and allow some or all of these to be redirected into investing.  
- Run two simulations: one with contributions only, and one with contributions plus redirected frugality.  
- Display tables and charts comparing the two approaches.  
- Highlight the long-term differences and the effect of redirecting small daily/weekly expenses.  

The output should be a ready-to-run `.ipynb` file with clear section headers for **Setup**, **Inputs**, **Simulator**, **Run**, and **Results**.
```
