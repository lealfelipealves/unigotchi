<template>
  <div class="home">
    <Nuvens />
    <div class="center">
      <Unigotchi />
    </div>
  </div>
</template>

<script>
// @ is an alias to /src
import Nuvens from '@/components/Nuvens.vue';
import Unigotchi from '@/components/Unigotchi.vue';

export default {
  name: 'home',
  components: {
    Nuvens,
    Unigotchi,
  },
};
</script>

<style>

.center{
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100vh;
}


</style>
