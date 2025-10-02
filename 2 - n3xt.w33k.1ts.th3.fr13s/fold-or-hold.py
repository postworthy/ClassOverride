
import random
import sys
import argparse

ASCII_BANNER = """
=======================================
    ______      __________    ________
   / ____/ __  / ___/__  /___/__  /__ \\
  /___ \\__/ /_/ __ \\  / /____/ / /__/ /
 ____/ /_  __/ /_/ / / /____/ / // __/
/_____/ /_/  \\____/ /_/      /_//____/

=======================================
"""

def compound_interest_game(rounds=30, random_losses=False, seed=None):
    if seed is not None:
        random.seed(seed)

    max_value = round(0.01 * (2 ** (rounds - 1)), 2)
    current_value = 0.01

    print(ASCII_BANNER)
    print(f"💰 You start with a single penny that doubles every round for {rounds} rounds")
    print(f"🏆 Your goal: decide each round whether to take a deal or double your money.")
    print(f"⚠️  Once you accept a deal, your game ends.")
    if random_losses:
        print(f"🎲 Random risk ON: There is a chance each HOLD round to suffer a catastrophic loss (your value is HALVED that round).")
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
            if random_losses and random.randint(1, 50) == 1:
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
                print(f"\n🎉 Congratulations! You held all {rounds} rounds.")
                print(f"💸 Your final winnings: ${current_value:,.2f}")
                print(f"🏦 The final bank offer was only: ${offer:,.2f}")
                print("📚 Lesson: Patience really does pay off!")
                break


def parse_args(argv):
    parser = argparse.ArgumentParser(
        description="Fold-or-Hold: a compound interest game with an optional random catastrophic loss mode (-r).",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )
    parser.add_argument("rounds", nargs="?", type=int, default=30,
                        help="Number of rounds to play (minimum 28).")
    parser.add_argument("-r", "--random", dest="random_losses", action="store_true",
                        help="Enable random catastrophic loss events (introduces a chance on HOLD rounds to halve your value).")
    parser.add_argument("--seed", type=int, default=None, help="Set RNG seed for reproducible runs.")
    args = parser.parse_args(argv)

    if args.rounds < 28:
        print("❌ Minimum number of rounds is 28")
        args.rounds = 28
    return args


if __name__ == "__main__":
    args = parse_args(sys.argv[1:])
    compound_interest_game(rounds=args.rounds, random_losses=args.random_losses, seed=args.seed)
