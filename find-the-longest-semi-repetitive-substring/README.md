<h2><a href="https://leetcode.com/problems/find-the-longest-semi-repetitive-substring">Find the Longest Semi-Repetitive Substring</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a <strong>0-indexed</strong> string <code>s</code> that consists of digits from <code>0</code> to <code>9</code>.</p>

<p>A string <code>t</code> is called a <strong>semi-repetitive</strong> if there is at most one consecutive pair of the same digits inside <code>t</code>.</p>

<p>Return <em>the length of the longest <strong>semi-repetitive</strong> substring inside</em> <code>s</code>.</p>

<p>A <b>substring</b> is a contiguous <strong>non-empty</strong> sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;52233&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest semi-repetitive substring is &quot;5223&quot;, which starts at i = 0 and ends at j = 3. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;5494&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> s is a semi-reptitive string, so the answer is 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1111111&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest semi-repetitive substring is &quot;11&quot;, which starts at i = 0 and ends at j = 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>&#39;0&#39; &lt;= s[i] &lt;= &#39;9&#39;</code></li>
</ul>
