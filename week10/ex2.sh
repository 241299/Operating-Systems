#!/usr/bin/env bash

file="../week01/file.txt"

echo > ${file} "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum varius, elit a pulvinar sollicitudin, nisl lectus tincidunt tortor, eget pharetra turpis elit et nibh. Nullam tincidunt, odio vel pharetra vulputate, nibh metus lacinia augue, fermentum euismod diam sapien quis lacus. Nunc ullamcorper, lacus condimentum dictum lacinia, erat purus auctor nulla, ut dictum turpis elit bibendum justo. In hac habitasse platea dictumst. Aenean eget mauris nisl. Etiam enim elit, luctus vel felis ut, consequat rhoncus justo. Integer a iaculis dui. Sed dictum scelerisque dolor, faucibus efficitur augue hendrerit ac. Integer ipsum lacus, aliquet at iaculis sit amet, gravida ut mauris. Mauris et ex non purus vestibulum suscipit. Proin porttitor eros in dolor vestibulum suscipit quis non purus. Donec porttitor odio nisi, ut euismod neque consectetur at. Aliquam ut augue at nisi consequat aliquet. Pellentesque finibus bibendum facilisis. Nulla justo lacus, placerat eu tellus et, feugiat tempus nibh. Vestibulum a nisl id ligula venenatis tempus."

link ${file} _ex2.txt

find ../ -inum $(ls -i ${file} | cut -d" " -f1)

find ../ -inum $(ls -i ${file} | cut -d" " -f1) -exec rm {} \;