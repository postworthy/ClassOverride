
import random
import sys

def compound_interest_game(rounds=30):
    max_value = round(0.01 * (2 ** (rounds - 1)), 2)
    current_value = 0.01

    print("""
=======================================
    ______      __________    ________
   / ____/ __  / ___/__  /___/__  /__ \\
  /___ \\__/ /_/ __ \\  / /____/ / /__/ /
 ____/ /_  __/ /_/ / / /____/ / // __/
/_____/ /_/  \\____/ /_/      /_//____/

=======================================
""")

    print(f"💰 You start with a single penny that doubles every round.")
    print(f"🏆 Your goal: decide each round whether to take a deal or double your money.")
    print(f"⚠️  Once you accept a deal, your game ends.\n")

    for round_number in range(1, rounds + 1):
        if round_number == 1:
            offer = 1_000_000
        else:
            midpoint = max_value * 0.5
            offer = round(random.uniform(1_000_000, min(midpoint, max_value - 1)), 2)

        print(f"\n\n--- Round {round_number} ---")
        print(f"💡 Current value if you HOLD: ${current_value:,.2f}")
        print(f"🏦 Bank offer if you FOLD:    ${offer:,.2f}")

        decision = input("\nDo you want to (h)old or (f)old? ").strip().lower()
        if decision == '':
            decision = 'h'
        while decision not in ['h', 'f', '']:
            decision = input("Please enter 'h' to hold or 'f' to fold: ").strip().lower()

        if decision == 'f':
            print(f"\n✅ You accepted the offer and walk away with ${offer:,.2f}!")
            print("📉 Let's see what you could have earned if you had held to the end...")
            print(f"🏁 Final round value would have been: ${max_value:,.2f}")
            break
        else:
            if round_number == 1:
                current_value = 0.02
            elif round_number == rounds:
                print(f"\n🎉 Congratulations! You held all {rounds} rounds.")
                print(f"💸 Your final winnings: ${current_value:,.2f}")
                print(f"🏦 The final bank offer was only: ${offer:,.2f}")
                print("📚 Lesson: Patience really does pay off!")
                break
            else:
                current_value *= 2

if __name__ == "__main__":
    if len(sys.argv) > 1:
        try:
            rounds = int(sys.argv[1])
            if rounds < 28:
                print("❌ Minimum number of rounds is 28")
                rounds = 28
        except ValueError:
            print("Invalid input. Usage: python3 fold-or-hold.py [number_of_rounds]")
            sys.exit(1)
    else:
        rounds = 30

    compound_interest_game(rounds)
