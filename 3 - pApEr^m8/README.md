# Adversarial Prompt Evolution (OpenAI)

This notebook is a hands‑on demo of **prompt evolution**: we start with a seed writing instruction (e.g., an 11th‑grade essay prompt), generate an essay with an LLM, **score** that essay with an AI‑text detector (Sapling), then **use the detector’s feedback to improve the prompt**. We repeat this loop until we get a stronger result while keeping the original style constraints intact.

Think of it like *iterative red‑teaming for prompts*: the model writes → a detector critiques → the prompt is refined → the model tries again.

---

## What you’ll learn
- **How to structure a prompt‑evolution loop** around an LLM (OpenAI) and a scoring function (Sapling’s AI‑detect API).
- **How to parse detector feedback** (overall score + sentence‑level scores) into actionable guidance.
- **How to preserve writing “invariants”** (tone/voice/constraints) while still evolving the instruction.
- **How to save the best artifacts** (prompt + essay) for review.

---

## Requirements
- **Python 3.9+**
- Packages: `openai`, `requests`, `pandas` (plus the standard library)
- API access:
  - **OpenAI** (models like `gpt-5`, `gpt-4o-mini`, etc.)
  - **Sapling AI Detect** (used as the scoring function)

Install the basics:
```bash
pip install --upgrade openai requests pandas
```

---

## Configuration
Set your API keys as environment variables before running the notebook:

```bash
export OPENAI_API_KEY="sk-..."
# Sapling: either set these as variables inside the notebook or export them here
export SAPLING_API_KEY="<your-sapling-key>"
export SAPLING_URL="https://api.sapling.ai/api/v1/aidetect"
```

Inside the notebook you can also pick your model:
```python
OPENAI_MODEL = "gpt-5"        # or "gpt-4o-mini", "o3-mini", etc.
OPENAI_THINK_MODEL = "gpt-5"  # optional think/reflect model (if used)
```

> **Tip:** If you don’t see `SAPLING_API_KEY`/`SAPLING_URL` set in code, define them in a small config cell or pull them from `os.environ`.

---

## How the scoring works
Sapling returns:
- a **`score`** for the full text (higher ⇒ more likely AI‑generated)
- **`sentence_scores`** with individual sentence risk

The notebook turns this into friendly feedback:
- An **overall summary** (“close to 1 = bad, close to 0 = good”)
- A **bulleted list** where the most risky sentences appear first, each with suggested action intensity.

This makes it easy to improve the prompt in the next round.

---

## Outputs
After a successful run you’ll find:
```
./outputs/passing_prompt.txt
./outputs/passing_essay.txt
```
These are the strongest prompt/essay found by the evolution loop (given the detector’s scoring and your constraints).

---

## Typical workflow
1. **Set keys & choose a model.**
2. **Pick (or paste) a seed instruction** that defines the voice and constraints you care about.
3. **Run the evolution cells.** Watch the printed rounds of prompt/essay/feedback.
4. **Stop when you’re happy** with the trade‑off between style and detector score.
5. **Grab the saved artifacts** from `./outputs/` for reuse or benchmarking.

---

## Notes & ethics
- This project is primarily educational: it shows how feedback loops can **stress‑test prompts** and **improve control** over model outputs.
- **Use responsibly.** Detector scores are imperfect; keep transparency in mind when publishing generated content.

---

## Troubleshooting
- **“NameError: SAPLING_API_KEY/SAPLING_URL not defined”**  
  Add a small setup cell or export them as environment variables (see *Configuration*).
- **HTTP errors from Sapling**  
  Check your key, network, or rate limits.
- **OpenAI auth errors**  
  Ensure `OPENAI_API_KEY` is set and your account has access to the selected model.
