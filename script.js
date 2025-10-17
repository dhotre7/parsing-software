const parseBtn = document.getElementById("parseCode");
const clearBtn = document.getElementById("clearOutput");
const codeArea = document.getElementById("codeArea");
const tokenOutput = document.getElementById("tokens");
const syntax = document.getElementById("syntax");
const ambiguity = document.getElementById("ambiguity");
const parseTree = document.getElementById("parseTree");

// Simple fake parser for demo
parseBtn.addEventListener("click", () => {
  const code = codeArea.value.trim();
  if (!code) {
    tokenOutput.textContent = "⚠️ Please enter code to parse!";
    return;
  }

  const tokens = code.split(/\s+/);
  tokenOutput.textContent = tokens.join("\n");

  syntax.textContent = "OK";
  ambiguity.textContent = "None Detected";

  parseTree.textContent = `Program\n  └── Parsed ${tokens.length} tokens`;
});

clearBtn.addEventListener("click", () => {
  tokenOutput.textContent = "No tokens yet.";
  parseTree.textContent = "No parse tree yet.";
  syntax.textContent = "-";
  ambiguity.textContent = "-";
});
