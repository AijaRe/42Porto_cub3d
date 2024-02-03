# cub3d_sandbox
Building repo for cub3d

## TODOs:
- Fill half the window with color of ceiling and the other with floor color, on begining of game. Draw walls on top;
- Function to check if map is bordered;
- Function to check if components are only "1,0, ,N,S,E,W" and that at only one (N,S,E,W) is present;
- Decide how to treat spaces (remove them or treat as 0?), what about space outside borders? (define as -1);
- How to get nr_lines from map, how to get the map from the file that has other info;
- Checker for other elements besides the map (textures and colors);
- Implement DDA algorithm;

## Links:
- [Raycasting and DDA](https://lodev.org/cgtutor/raycasting.html) (contains 2 files with implementations in c++)
- [Raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) (easier to understand) (Currently basing on this one)
- [Creating a raycaster](https://www.youtube.com/watch?v=gYRrGTC7GtA) (series of 3 videos)

- Personal page for [notes](https://spicy-dirigible-2b6.notion.site/Cub3D-cc92684cfbf64eb8ae13841b32ea4603?pvs=4)

Using this as reference for orientation in map:   
![image](https://github.com/damachad/cub3d_sandbox/assets/128734978/dfe879ec-18be-4987-a7c4-a59e359449b4)

Top left corner (even if it has to be imagined, when map shape does not allow it) coincides with grid coordinate (0,0). E is 0°, N is 90°, W is 180° and S is 270°.
