
import random
import sys
import argparse
import math

ASCII_BANNER = """
=======================================
    ______      __________    ________
   / ____/ __  / ___/__  /___/__  /__ \\
  /___ \\__/ /_/ __ \\  / /____/ / /__/ /
 ____/ /_  __/ /_/ / / /____/ / // __/
/_____/ /_/  \\____/ /_/      /_//____/

=======================================
"""

def expected_multiplier(random_losses: bool, odds: int) -> float:
    """
    Per-round expected multiplier:
      - No random losses: 2.0 (deterministic doubling)
      - With losses (1-in-odds halves instead of doubles):
            E = (1 - 1/odds)*2 + (1/odds)*0.5 = 2 - 1.5/odds
    """
    if not random_losses:
        return 2.0
    if odds <= 0:
        return 2.0
    return 2.0 - (1.5 / odds)


def describe_strategy(rounds: int, random_losses: bool, odds: int) -> str:
    mu = expected_multiplier(random_losses, odds)
    if not random_losses:
        final_val = round(0.01 * (2 ** (rounds - 1)), 2)
        return (
f"""
Optimal play (no risk): Always HOLD. Value doubles each round deterministically.
Final value if you hold {rounds} rounds: ${final_val:,.2f}.
"""
        )
    # Transparency text kept ASCII-safe to avoid encoding issues
    return (
f"""
Optimal play with catastrophic risk:
- Catastrophe odds: 1 in {odds} per HOLD round (value HALVED that round).
- Per-round expected growth mu ~= {mu:.4f}.
- EV-threshold rule each round:
    If bank offer >= current_value * (mu ** remaining_rounds) -> FOLD, else HOLD.
"""
    )


def compound_interest_game(rounds=30, random_losses=False, seed=None, transparent=False, odds=50):
    if seed is not None:
        random.seed(seed)

    max_value = round(0.01 * (2 ** (rounds - 1)), 2)
    current_value = 0.01
    mu = expected_multiplier(random_losses, odds)

    print(ASCII_BANNER)
    print(f"💰 You start with a single penny that doubles every round for {rounds} rounds")
    print(f"🏆 Your goal: decide each round whether to take a deal or double your money.")
    print(f"⚠️  Once you accept a deal, your game ends.")
    if random_losses:
        print(f"🎲 Random risk ON: 1-in-{odds} chance each HOLD to suffer a catastrophic loss (your value is HALVED that round).")
    print()

    if transparent:
        print("🔎 Transparency mode (optimal policy guidance):")
        print(describe_strategy(rounds, random_losses, odds))
        print()

    for round_number in range(1, rounds + 1):
        # Compute bank offer
        if round_number == 1:
            offer = 1_000_000
        else:
            midpoint = max_value * 0.5
            offer = round(random.uniform(1, min(midpoint, max_value - 1)), 2)

        print(f"\n\n--- Round {round_number} ---")
        print(f"💡 Current value if you HOLD: ${current_value:,.2f}")
        print(f"🏦 Bank offer if you FOLD:    ${offer:,.2f}")

        # Transparency: print optimal recommendation (does not force the player)
        if transparent:
            remaining = rounds - round_number
            threshold = current_value * (mu ** remaining)
            recommendation = "FOLD" if offer >= threshold else "HOLD"
            print(f"🤖 Optimal policy says: {recommendation} "
                  f"(threshold ≈ ${threshold:,.2f} from μ={mu:.4f})")

        decision = input("\nDo you want to (h)old or (f)old? ").strip().lower()
        if decision == '':
            decision = 'h'
        while decision not in ['h', 'f']:
            decision = input("Please enter 'h' to hold or 'f' to fold: ").strip().lower()

        if decision == 'f':
            print(f"\n✅ You accepted the offer and walk away with ${offer:,.2f}!")
            print("📉 Let's see what you could have earned if you had held to the end...")
            print(f"🏁 Final round value would have been: ${max_value:,.2f}")
            break
        else:
            # HOLD path
            if random_losses and random.randint(1, odds) == 1:
                # Catastrophic loss event: halve value instead of doubling this round
                before = current_value
                current_value = round(current_value / 2, 2)
                print(f"\n💥 Catastrophic loss event! Your value is HALVED this round: ${before:,.2f} → ${current_value:,.2f}")
            else:
                # Normal doubling logic
                if round_number == 1:
                    current_value = 0.02
                else:
                    current_value = round(current_value * 2, 2)

            if round_number == rounds:
                print(f"\n🎉 You held all {rounds} rounds.")
                print(f"💸 Your final winnings: ${current_value:,.2f}")
                print(f"🏦 The final bank offer was: ${offer:,.2f}")
                break


def parse_args(argv):
    parser = argparse.ArgumentParser(
        description="Fold-or-Hold: compound growth game with optional random catastrophic losses (-r) and transparent strategy tips (-t).",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )
    parser.add_argument("rounds", nargs="?", type=int, default=30,
                        help="Number of rounds to play (minimum 28).")
    parser.add_argument("-r", "--random", dest="random_losses", action="store_true",
                        help="Enable random catastrophic loss events (1-in-ODDS chance on HOLD rounds to halve your value).")
    parser.add_argument("--odds", type=int, default=50,
                        help="Catastrophe odds denominator when -r is enabled (e.g., 15 → 1-in-15; 25 → 1-in-25).")
    parser.add_argument("-t", "--transparent", action="store_true",
                        help="Show optimal-policy description at start and per-turn recommended action.")
    parser.add_argument("--seed", type=int, default=None, help="Set RNG seed for reproducible runs.")
    args = parser.parse_args(argv)

    if args.rounds < 28:
        print("❌ Minimum number of rounds is 28")
        args.rounds = 28
    if args.odds < 1:
        args.odds = 1
    return args


if __name__ == "__main__":
    args = parse_args(sys.argv[1:])
    compound_interest_game(rounds=args.rounds,
                           random_losses=args.random_losses,
                           seed=args.seed,
                           transparent=args.transparent,
                           odds=args.odds)
