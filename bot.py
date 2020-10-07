#!/usr/bin/env python3

import sys
import discord
import useless_bot

class DiscordWrapper(discord.Client):
  def __init__(self, backend):
    discord.Client.__init__(self)
    self._backend = backend

  async def on_ready(self):
    usr = useless_bot.User(self.user.id, self.user.name)
    self._backend.on_ready(usr)

  async def on_message(self, message):
    if message.author == self.user:
      return
    
    print("Message: ", message)

if __name__ == "__main__":
  if len(sys.argv) != 2:
    print("Error: expected exactly 1 command line argument with the bot token", file=sys.stderr)
    #TODO: accept the token via environment variables?
    sys.exit(1)

  client = DiscordWrapper(useless_bot.BotCore())
  client.run(sys.argv[1])
