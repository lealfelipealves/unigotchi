<template>
  <div id='background-wrap'>
    <div :class='`x` + index' v-for="index in 10" :key="index">
      <div class="cloud"></div>
    </div>
  </div>
</template>

<script>

</script>

<style>

body {
  background: #00b4ff;
  color: #333;
  height: 100vh;
  margin: 0;
  padding: 0;
  overflow-x: hidden;
}

#background-wrap {
  bottom: 0;
  left: 0;
  padding-top: 50px;
  position: fixed;
  right: 0;
  top: 0;
  z-index: -1;
}

@keyframes animateCloud
{
  0% { margin-left: -1000px; }
  100% { margin-left: 100%; }
}

.x1 {
  animation: animateCloud 35s linear infinite;
  transform: scale(0.65);
}

.x2 {
  animation: animateCloud 20s linear infinite;
  transform: scale(0.3);
}

.x3 {
  animation: animateCloud 30s linear infinite;
  transform: scale(0.5);
}

.x4 {
  animation: animateCloud 18s linear infinite;
  transform: scale(0.4);
}

.x5 {
  animation: animateCloud 25s linear infinite;
  transform: scale(0.55);
}

.x6 {
  animation: animateCloud 15s linear infinite;
  transform: scale(0.36);
}

.x7 {
  animation: animateCloud 25s linear infinite;
  transform: scale(0.60);
}

.x8 {
  animation: animateCloud 28s linear infinite;
  transform: scale(0.36);
}

.x9 {
  animation: animateCloud 12s linear infinite;
  transform: scale(0.36);
}

.cloud {
  background: white;
  background: linear-gradient(top, white 5%, #f1f1f1 100%);
  border-radius: 100px;
  box-shadow: 0 8px 5px rgba(0,0,0,0.1);
  height: 120px;
  position: relative;
  width: 350px;
}


.cloud:after, .cloud:before {
  position: absolute;
  content: '';
  background: white;
  z-index: -1;
}

.cloud:after {
  border-radius: 100px;
  height: 100px;
  left: 50px;
  top: -50px;
  width: 100px;
}

.cloud:before {
  border-radius: 200px;
  height: 180px;
  width: 180px;
  right: 50px;
  top: -90px;
}

</style>
