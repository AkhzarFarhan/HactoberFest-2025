import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 640, 480
GREEN = (0, 255, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
BLACK = (0, 0, 0)

# Set up the display
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Press Bar Game")

# Bar and button properties
bar_width = 260
bar_height = 40
bar_x = (WIDTH - bar_width) // 2
bar_y = (HEIGHT - bar_height) // 2
button_width = 150
button_height = 30
button_x = random.randint(0, WIDTH - button_width)
button_y = random.randint(0, HEIGHT - button_height)

# Game loop
def game_loop():
    global button_x, button_y

    # Countdown before game starts
    for countdown in range(3, 0, -1):
        screen.fill(BLACK)
        font = pygame.font.Font(None, 74)
        text = font.render(str(countdown), True, RED)
        screen.blit(text, (WIDTH // 2 - text.get_width() // 2, HEIGHT // 2 - text.get_height() // 2))
        pygame.display.flip()
        pygame.time.delay(1000)

    while True:
        screen.fill(BLUE)

        # Draw the bar
        pygame.draw.rect(screen, GREEN, (bar_x, bar_y, bar_width, bar_height))

        # Draw the button
        pygame.draw.rect(screen, RED, (button_x, button_y, button_width, button_height))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            if event.type == pygame.MOUSEMOTION:
                mouse_x, mouse_y = event.pos
                if button_x < mouse_x < button_x + button_width and button_y < mouse_y < button_y + button_height:
                    # If the mouse is over the button, move the button
                    button_x = random.randint(0, WIDTH - button_width)
                    button_y = random.randint(0, HEIGHT - button_height)

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    sys.exit()

        # Update the display
        pygame.display.flip()

# Run the game
if __name__ == "__main__":
    game_loop()
