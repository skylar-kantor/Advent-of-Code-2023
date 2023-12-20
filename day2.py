input_file = open('input2', 'r')

in_lines = input_file.readlines()
bad_games = []
for line in in_lines:
    game_id, rounds =  line.split(":")
    game_id = int(game_id.split(" ")[1])
    rounds = rounds.split(";")
    blues = []
    greens = []
    reds = []
    for round in rounds:
        round = round.split(",")
        #print(round)
        for color in round:
             count, color = color.split(" ")[1:]
             #print(count, color)
             if "red" in color:
                reds.append(int(count))
             if "blue" in color:
                blues.append(int(count))
             if "green" in color:
                greens.append(int(count))
    blue_ok = red_ok = green_ok = True
    #print(f"Game {game_id} reds: {reds}, greens: {greens}, blues: {blues}")
    for red in reds:
        if red > 12:
            print(f"{red} reds in game {game_id}")
            bad_games.append(game_id)
            red_okay = False
            break
    for green in greens:
        if green > 13:
            bad_games.append(game_id)
            print(f"{green} greens in game {game_id}")
            green_okay = False
            break
    for blue in blues:
        
        if blue > 14:
            bad_games.append(game_id)
            print(f"{blue} blues in game {game_id}")
            blue_okay = False
            break
bad_games = set(bad_games)
all_games = set(range(1,101))
good_games = all_games-bad_games
good_games = list(good_games)
print(sum(good_games))



