# Spare parts opgave 

Draw a flowchart for this [problem](#problem).
> flowchart : [Flowchart](flowchartSpaceParts.png)

Make code to solve the [problem](#problem)
> da code : [code](.src/main.c)

---

## Problem 
You will program a chat assistant that gives information about the availability of industrial spare parts in the inventory. The assistant repeatedly asks the user which part they need and the user replies whether they would like to have or not.

The parts in the inventory are: hydraulic pump, PLC module, servo motor.

The assistant starts the conversation with

    Hej. Welcome to the spare parts inventory!
    Which part do you need?

Then, in a loop, repeatedly ask the user which parts they need. If you user enters the exact name of a part that is in the inventory, affirm that you have the part in the format:

    I have got {part} here for you 😊. Bye!

If the user does not enter the exact name:

    I am afraid we don’t have any {part} in the inventory 😔

There can also be special queries like:

    - Do you actually have any parts?
    - Is there anything in stock at all?

Then the assistant must reply with the number of parts and their names, one on each line:

    We have {part_count} part(s)!

The program exits, only after the assistant affirms that a part is available.


### Sample interaction
```
- Hej. Welcome to the spare parts inventory!
- Which part do you need? gripper
- I am afraid we don't have any gripper in the inventory 😔
- Which part do you need? plc module
- I am afraid we don't have any plc module in the inventory 😔
- Which part do you need? PLC module
- I've got PLC module here for you 😊
- (program exits)

```