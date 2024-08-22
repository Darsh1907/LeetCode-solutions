# 3248. Snake in Matrix
## (Easy)

There is a snake in an `n x n` matrix `grid` and can move in four possible directions. Each cell in the `grid` is identified by the position: `grid[i][j] = (i * n) + j`.

The snake starts at cell `0` and follows a sequence of commands.

You are given an integer `n` representing the size of the grid and an array of strings `commands` where each `command[i]` is either `"UP"`, `"RIGHT"`, `"DOWN"`, and `"LEFT"`. It's guaranteed that the snake will remain within the `grid` boundaries throughout its movement.

Return the position of the final cell where the snake ends up after executing `commands`.

![alt text](image.png)

Constraints:

- `2 <= n <= 10`
- `1 <= commands.length <= 100`
- commands consists only of `"UP"`, `"RIGHT"`, `"DOWN"`, and `"LEFT"`.
- The input is generated such the snake will not move outside of the boundaries.