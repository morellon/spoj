tests, divider = gets.chomp.split(/\s+/)
divider = divider.to_i
count = 0
inputs = STDIN.read
inputs.each_line do |line|
  count += 1 if line.to_i % divider == 0
end
puts count