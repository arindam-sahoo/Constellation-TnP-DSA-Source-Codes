def coin_change(deno, amt):
    nums = [0] * len(deno)
    for i in range(len(deno) - 1, -1, -1):
        while amt >= deno[i]:
            amt -= deno[i]
            nums[i] += 1

    print("The Denominations are:")
    for i in range(len(deno) - 1, -1, -1):
        if nums[i] > 0:
            print(f"{nums[i]} x {deno[i]}")

if __name__ == "__main__":
    deno = [1, 2, 5, 10, 20, 50, 100, 200, 500]
    amt = 2898

    coin_change(deno, amt)
